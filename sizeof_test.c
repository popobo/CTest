int test(int in) {
    char temp[in];
    int temp1 = sizeof(temp) / sizeof(temp[0]);
    return temp1;
}

int main() {
    test(1);
    test(2);
}