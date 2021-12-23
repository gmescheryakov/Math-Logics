#include <bdd.h>
#include <fstream>
#include <memory>
#include <cmath>
#include <vector>
#include <cassert>


std::ofstream out;
const int N = 9; // Система из N объектов, принимающих различные значения
const int M = 4; // Обладающих M свойствами
const int N_SQRT = sqrt(N);
const int LOG_N = std::ceil(std::log2(N)); //Максимальное изменение индекса, отвечающего за бит свойства
char *var;
int arr[N][M];

enum class Neighbour {
    UP,
    LEFTDOWN
};

void fun(char *varset, int size);  //Для вывода решения

void init(bdd p[M][N][N]);

bdd limit_1(const bdd p[M][N][N], int m, int n, int value); // ограничения 1-го типа
bdd limit_2(const bdd p[M][N][N], int m1, int value1, int m2, int value2); // ограничения 2-го типа
bdd limit_3(const bdd p[M][N][N], Neighbour neighbour, int m1, int value1, int m2,
            int value2); // ограничения 3-го типа
bdd limit_4(const bdd p[M][N][N], int m1, int value1, int m2, int value2); // ограничения 4-го типа
void limit_5(bdd &tree, const bdd p[M][N][N]);

bdd limit_6(const bdd p[M][N][N]);

int main() {
//    var = std::make_unique<char[]>(N * M * LOG_N).get();
    var = new char[N * M * LOG_N];

    //Инициализация
    bdd_init(10000000, 1000000);
    bdd_setvarnum(N * M * LOG_N); // число используемых булевых переменных

    //вводим функцию p(k, i, j) следующим образом (кодируем p[k][i][j] в виде трехмерного вектора для масштабирования)
    bdd p[M][N][N];
    init(p);

    //Вводим ограничения
    bdd task = bddtrue;

    // ограничение 1:  Свойство m у объекта n = value

    std::ifstream fin("../cond1.txt");
    int n;
    fin >> n;
    for (int i = 0; i < n; ++i) {
        int m, x, value;
        fin >> m >> x >> value;
        task &= limit_1(p, m, x, value);
    }
    fin.close();

    // ограничение 2
    // Если у объекта св-во m1 = value1, то св-во m2 = value2 и наоборот
    fin.open("../cond2.txt");
    fin >> n;
    for (int i = 0; i < n; ++i) {
        int m1, value1, m2, value2;
        fin >> m1 >> value1 >> m2 >> value2;
        task &= limit_2(p, m1, value1, m2, value2);
    }
    fin.close();

    // ограничение 3
    // Позиция 2-го относительно 1-го
    fin.open("../cond3.txt");
    fin >> n;
    for (int i = 0; i < n; ++i) {
        std::string neighbour;
        int m1, value1, m2, value2;
        fin >> neighbour >> m1 >> value1 >> m2 >> value2;
        if (neighbour == "LEFTDOWN") {
            task &= limit_3(p, Neighbour::LEFTDOWN, m1, value1, m2, value2);
        } else if (neighbour == "UP") {
            task &= limit_3(p, Neighbour::UP, m1, value1, m2, value2);
        } else {
            std::cout << "exception";
            exit(-1);
        }
    }
    fin.close();

    // ограничение 4
    // Если у объекта свойство m1 имеет значение value, то он располагается слева-внизу или сверху от объекта, у которого св-во m2 = value2
    fin.open("../cond4.txt");
    fin >> n;
    for (int i = 0; i < n; ++i) {
        int m1, value1, m2, value2;
        fin >> m1 >> value1 >> m2 >> value2;
        task &= limit_4(p, m1, value1, m2, value2);
    }
    fin.close();

    // ограничение 5
    // У двух различных параметров значения свойств не совпадают
    limit_5(task, p);

    // ограничение 6
    // Параметры принимают значения только из заданных множеств (значение свойств меньше N)
    task &= limit_6(p);

    // Вывод
    out.open("out.txt");

    auto satcount = (int) bdd_satcount(task); // количество решений

    out << satcount << " solutions:\n" << std::endl;
    std::cout << satcount << " solutions\n" << std::endl;

    if (satcount) {
        bdd_allsat(task, fun);  //решение
    }
    std::cout << satcount << " solutions\n" << std::endl;

    out.close();
    bdd_done(); //Завершение работы с библиотекой

    return 0;
}

void print() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int J = i * M * LOG_N + j * LOG_N;
            int num = 0;

            for (int k = 0; k < LOG_N; k++) {
                num += (int) (var[J + k] << k);
            }

            arr[i][j] = num;
        }
    }

    for (int i = 0; i < N; i++) {
        std::cout << i << ": ";
        out << i << ": ";

        for (int j = 0; j < M; j++) {
            std::cout << arr[i][j] << " ";
            out << arr[i][j] << " ";
        }

        std::cout << "\n";
        out << "\n";
    }
    std::cout << "\n";
    out << "\n";
}

void build(char *varset, unsigned n, unsigned I) {
    if (I == n - 1) {
        if (varset[I] >= 0) {
            var[I] = varset[I];
            print();
            return;
        }
        var[I] = 0;
        print();
        var[I] = 1;
        print();
        return;
    }
    if (varset[I] >= 0) {
        var[I] = varset[I];
        build(varset, n, I + 1);
        return;
    }
    var[I] = 0;
    build(varset, n, I + 1);
    var[I] = 1;
    build(varset, n, I + 1);
}

void fun(char *varset, int size)  //Для bdd_allsat
{
    build(varset, size, 0);
}

void init(bdd p[M][N][N]) {
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                p[i][j][k] = bddtrue;
                for (int l = 0; l < LOG_N; ++l) {
                    p[i][j][k] &= ((k >> l) & 1) ? bdd_ithvar((j * LOG_N * M) + l + LOG_N * i)
                                                 : bdd_nithvar((j * LOG_N * M) + l + LOG_N * i);
                }
            }
        }
    }
}

bdd limit_1(const bdd p[M][N][N], int m, int n, int value) {
    return p[m][n][value];
}

bdd limit_2(const bdd p[M][N][N], int m1, int value1, int m2, int value2) {
    bdd tree = bddtrue;
    for (int i = 0; i < N; ++i) {
        tree &= !(p[m1][i][value1] ^ p[m2][i][value2]);
    }

    return tree;
}

bdd limit_3(const bdd p[M][N][N], Neighbour neighbour, int m1, int value1, int m2, int value2) {
    bdd tree = bddtrue;

    switch (neighbour) {
        case Neighbour::UP:
        {
            for (int i = 0; i < N; ++i) {
                if (i < N_SQRT) {
                    tree &= !p[m1][i][value1];
                }
                else {
                    tree &= !(p[m1][i][value1] ^ p[m2][i - N_SQRT][value2]);
                }
            }
            break;
        }
        case Neighbour::LEFTDOWN:
        {
            for (int i = 0; i < N; ++i) {
                if ((i % N_SQRT == 0) && (i != N - N_SQRT)) {
                    tree &= !p[m1][i][value1];
                }
                else if (i >= N - N_SQRT) {
                    tree &= !(p[m1][i][value1] ^ p[m2][((i % N_SQRT) + N_SQRT - 1) % N_SQRT][value2]);
                }
                else {
                    tree &= !(p[m1][i][value1] ^ p[m2][(i + N_SQRT - 1)][value2]);
                }
            }
            break;
        }
        default:
            assert("Error");
            std::cerr << "wrong input";
            break;
    }
    return tree;
}

bdd limit_4(const bdd p[M][N][N], int m1, int value1, int m2, int value2) {
    bdd tree = bddfalse;
    static const Neighbour arr[] = {Neighbour::UP, Neighbour::LEFTDOWN};
    std::vector<Neighbour> neighbours(arr, arr + sizeof(arr) / sizeof(arr[0]));

    for (Neighbour neighbour: neighbours) {
        tree |= limit_3(p, neighbour, m1, value1, m2, value2);
    }

    return tree;
}

void limit_5(bdd &tree, const bdd p[M][N][N]) { // свойства не совпадают
    for (unsigned j = 0; j < N; j++) {
        for (unsigned i = 0; i < N - 1; i++) {
            for (unsigned k = i + 1; k < N; k++) {
                for (unsigned m = 0; m < M; m++) {
                    tree &= p[m][i][j] >> !p[m][k][j];
                }
            }
        }
    }
}

bdd limit_6(const bdd p[M][N][N]) { //параметры принимают значения только из заданных множеств
    bdd tree = bddtrue;
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < M; ++k) {
            bdd temp0 = bddfalse;
            for (int j = 0; j < N; j++) {
                temp0 |= p[k][i][j];
            }
            tree &= temp0;
        }
    }

    return tree;
}
