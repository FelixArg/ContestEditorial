import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;
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
        long n = in.nextLong();
        Map<Integer, Integer> m = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int p = in.nextInt();
            if (m.containsKey(p - 1)) {
                m.put(p, m.get(p - 1) + 1);
            } else {
                m.put(p, 1);
            }
        }
        int max = 0;
        for (Map.Entry<Integer, Integer> entry : m.entrySet()) {
            max = Math.max(max, entry.getValue());
        }
        out.print(n - max);
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