
import java.util.*;

public class Playfair {
    static char[][] m = new char[5][5];

    static void makeKey(String key) {
        String s = (key + "ABCDEFGHIKLMNOPQRSTUVWXYZ").toUpperCase();
        String t = "";

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c >= 'A' && c <= 'Z') {
                if (c == 'J') c = 'I';
                if (t.indexOf(c) == -1) t += c;
            }
        }

        for (int i = 0; i < 25; i++)
            m[i/5][i%5] = t.charAt(i);
    }

    static String play(String s, int d) {
        s = s.toUpperCase().replace("J", "I");
        String out = "";

        if (d == 1) {
            for (int i = 0; i < s.length();) {
                char a = s.charAt(i++);
                char b = (i < s.length()) ? s.charAt(i) : 'X';

                if (a == b) b = 'X';
                else i++;

                out += "" + a + b;
            }
        } else {
            out = s;
        }

        String result = "";

        for (int i = 0; i < out.length(); i += 2) {
            char a = out.charAt(i), b = out.charAt(i+1);
            int r1=0, c1=0, r2=0, c2=0;

            for (int r=0; r<5; r++)
                for (int c=0; c<5; c++) {
                    if (m[r][c] == a) { r1=r; c1=c; }
                    if (m[r][c] == b) { r2=r; c2=c; }
                }

            if (r1 == r2) {
                c1 = (c1+d+5)%5;
                c2 = (c2+d+5)%5;
            }
            else if (c1 == c2) {
                r1 = (r1+d+5)%5;
                r2 = (r2+d+5)%5;
            }
            else {
                int temp = c1;
                c1 = c2;
                c2 = temp;
            }

            result += "" + m[r1][c1] + m[r2][c2];
        }

        return result;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter key: ");
        String key = sc.next();

        System.out.print("Enter text: ");
        String text = sc.next();

        makeKey(key);

        System.out.println("Encrypted: " + play(text, 1));
        System.out.println("Decrypted: " + play(play(text, 1), -1));
    }
}


// --------------
//   sample output:
// Enter key: MONARCHY
// Enter text: INSTRUMENTS
// Encrypted: GATLMZCLRQXA
// Decrypted: INSTRUMENTSX
