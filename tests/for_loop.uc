_x = 0;

loop (x = 0; x < 4; x++) {
    when (x == 2) {
        moveon;
    }
    when (x == 3) {
        stop;
    } otherwise {
        show(x);
    }
}
