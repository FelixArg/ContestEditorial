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
    static int [] a = new int[400000];
    static int [] b = new int[400000];
    public static void solve(InputReader in, PrintWriter out) {
        long n = in.nextLong();
        long m = in.nextLong();
        int f = in.nextInt();
        int c = in.nextInt();
        for (int i=0;i<m-1;i++){
            int f1 = in.nextInt();
            int c1 = in.nextInt();
            if (f1==f || c1==f)
            {
                a[f]+=1;
            } else {
                a[f1]++;
                a[c1]++;
            }
            if (f1==c || c1==c)
            {
                b[c]+=1;
            } else {
                b[f1]++;
                b[c1]++;
            }
        }
        for (int i=0;i<=n;i++){
            if (i!=f && a[f]+a[i]==m-1)
            {
                out.print("YES");
                return;
            }
            if (i!=c && b[c]+b[i]==m-1)
            {
                out.print("YES");
                return;
            }
        }
        out.print("NO");
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