int test1() {
    return 10;
}

int test2() {
    int sum = 0;
    for (int i = 0; i < 100; i++) {
        sum += i;
    }
    return sum;
}

int main() {
    int i = test2();
    return i;
}