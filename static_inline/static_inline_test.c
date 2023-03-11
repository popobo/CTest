void test3();

static void test2 () {

}

int test1();

inline int test1() {
    // test2();
    // test3();
    int i = 0;
    i++;
    return i;
}

int main() {
    int i = test1();
    return i;
}