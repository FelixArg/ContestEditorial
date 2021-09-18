import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

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
        long n = in.nextLong();
        long k = in.nextLong();
        long a = in.nextLong();
        long b = in.nextLong();
        char ca = 'G';
        char cb = 'B';
        if (a > b) {
            long t = a;
            a = b;
            b = t;
            char c = ca;
            ca = cb;
            cb = c;
        }
        StringBuilder st = new StringBuilder();
        while (a != 0) {
            for (int i = 0; i < k && b != 0; i++) {
                st.append(cb);
                b--;
            }
            st.append(ca);
            a--;
            while (a > b) {
                a--;
                st.append(ca);
            }
        }
        if (b > k) {
            out.print("NO");
        } else {
            for (int i = 0; i < b; i++) {
                st.append(cb);
            }
            out.print(st.toString());
        }
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

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }
}