import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.Random;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        solve(in, out);
        out.close();
    }

    public static void solve(InputReader in, PrintWriter out) {
        int n = Integer.parseInt(in.next());
        long min_value = (1l << 61);
        long max_value = -(1l<< 61);

        for (int i = 0; i < n; i++) {
            long x = Long.parseLong(in.next());
            min_value = Math.min(min_value, x);
            max_value = Math.max(max_value, x);
        }

        if (min_value >= -128 && max_value <= 127)
            out.println("byte");
        else if (min_value >= -32768 && max_value <= 32767)
            out.println("short");
        else if (min_value >= -2147483648 && max_value <= 2147483647)
            out.println("int");
        else
            out.println("long");
    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

    }
}