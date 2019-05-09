package FastIO;

import java.io.*;

public class OutputWriter {
    private final PrintWriter writer;

    public OutputWriter(OutputStream outputStream) {
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }

    public OutputWriter(Writer writer) {
        this.writer = new PrintWriter(writer);
    }

    public void print(char[] array) {
        writer.print(array);
    }

    public void print(Object... objects) {
        for (int i = 0; i < objects.length; i++) {
            if (i != 0) {
                writer.print(' ');
            }
            writer.print(objects[i]);
        }
    }

    public void print(int[] array) {
        for (int i = 0; i < array.length; i++) {
            if (i != 0) {
                writer.print(' ');
            }
            writer.print(array[i]);
        }
    }

    public void print(double[] array) {
        for (int i = 0; i < array.length; i++) {
            if (i != 0) {
                writer.print(' ');
            }
            writer.print(array[i]);
        }
    }

    public void print(long[] array) {
        for (int i = 0; i < array.length; i++) {
            if (i != 0) {
                writer.print(' ');
            }
            writer.print(array[i]);
        }
    }

    public void println(int[] array) {
        print(array);
        writer.println();
    }

    public void println(double[] array) {
        print(array);
        writer.println();
    }

    public void println(long[] array) {
        print(array);
        writer.println();
    }

    public void println() {
        writer.println();
    }

    public void println(Object... objects) {
        print(objects);
        writer.println();
    }

    public void print(char i) {
        writer.print(i);
    }

    public void println(char i) {
        writer.println(i);
    }

    public void print(int count, String s) {
        writer.print(Utilities.repeat(count, s));
    }

    public void println(int count, String s) {
        writer.println(Utilities.repeat(count, s));
    }

    public void print(int count, Character s) {
        writer.print(Utilities.repeat(count, s.toString()));
    }

    public void println(int count, Character s) {
        writer.println(Utilities.repeat(count, s.toString()));
    }

    public void println(char[] array) {
        writer.println(array);
    }

    public void printf(String format, Object... objects) {
        writer.printf(format, objects);
    }

    public void close() {
        writer.close();
    }

    public void flush() {
        writer.flush();
    }

    public void print(long i) {
        writer.print(i);
    }

    public void println(long i) {
        writer.println(i);
    }

    public void print(int i) {
        writer.print(i);
    }

    public void println(int i) {
        writer.println(i);
    }

    public void separateLines(int[] array) {
        for (int i : array) {
            println(i);
        }
    }
}
