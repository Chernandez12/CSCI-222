
// send.cpp
void send(char * msg = "test", int times = 1); void send(char *, int);
int main() {
    send();
    send("hello");
    send("hello", 3);
    return 0;
}