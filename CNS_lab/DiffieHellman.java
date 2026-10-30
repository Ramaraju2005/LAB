
import java.util.Scanner;

public class DiffieHellman {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        long p, g, a, b;
        long x, y, keyA, keyB;

        System.out.print("Enter prime number (p): ");
        p = sc.nextLong();

        System.out.print("Enter primitive root (g): ");
        g = sc.nextLong();

        System.out.print("Enter private key of Alice: ");
        a = sc.nextLong();

        System.out.print("Enter private key of Bob: ");
        b = sc.nextLong();

        // Alice calculates public key
        x = power(g, a, p);

        // Bob calculates public key
        y = power(g, b, p);

        System.out.println("\nAlice Public Key: " + x);
        System.out.println("Bob Public Key: " + y);

        // Both calculate shared secret key
        keyA = power(y, a, p);
        keyB = power(x, b, p);

        System.out.println("Alice Shared Key: " + keyA);
        System.out.println("Bob Shared Key: " + keyB);

        if (keyA == keyB)
            System.out.println("Key Exchange Successful!");
        else
            System.out.println("Key Exchange Failed!");

        sc.close();
    }

    static long power(long base, long exp, long mod) {
        long result = 1;

        while (exp > 0) {
            if (exp % 2 == 1)
                result = (result * base) % mod;

            base = (base * base) % mod;
            exp /= 2;
        }

        return result;
    }
}

// sample output:
// Enter prime number (p): 23
// Enter primitive root (g): 5
// Enter private key of Alice: 6
// Enter private key of Bob: 15

// Alice Public Key: 8
// Bob Public Key: 19

// Alice Shared Key: 2
// Bob Shared Key: 2

// Key Exchange Successful!
