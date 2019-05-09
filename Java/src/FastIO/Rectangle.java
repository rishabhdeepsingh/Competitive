package FastIO;

class Rectangle {
    private final Point topLeft;
    private final Point bottomRight;

    public Rectangle(Point topLeft, Point bottomRight) {
        this.topLeft = topLeft;
        this.bottomRight = bottomRight;
    }

    public boolean isOverLapping(Rectangle other) {
        if (this.topLeft.x > other.bottomRight.x // R1 is right to R2
                || this.bottomRight.x < other.topLeft.x // R1 is left to R2
                || this.topLeft.y < other.bottomRight.y // R1 is above R2
                || this.bottomRight.y > other.topLeft.y) { // R1 is below R1
            return false;
        }
        return true;
    }
}
