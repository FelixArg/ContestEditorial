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

    static String[] a = new String[400];

    public static void solve(InputReader in, PrintWriter out) {
        long n = in.nextLong();
        for (int i = 0; i < n; i++) {
            a[i] = in.next();
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i].charAt(j) != 'C') {
                    continue;
                }
                for (int i1 = 0; i1 < n; i1++) {
                    if (a[i1].charAt(j) == 'C') {
                        ans++;
                    }
                }
                for (int i1 = 0; i1 < n; i1++) {
                    if (a[i].charAt(i1) == 'C') {
                        ans++;
                    }
                }
                ans -= 2;
            }
        }
        ans = ans / 2;
        out.print(ans);
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