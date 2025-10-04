// author: carandp

import java.math.BigInteger;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

class Main {
    public static void main(String[] args) {
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        try {
            String nr = r.readLine();
            Integer n = Integer.parseInt(nr);

            for (int i = 0; i < n; i++) {
                String rInit = r.readLine();
                String[] rs = rInit.split(" ");
                BigInteger l1 = new BigInteger(rs[0]);
                BigInteger l2 = new BigInteger(rs[1]);
                BigInteger result = l1.multiply(l2);
                System.out.println(result);
            }
        } catch (IOException e) { }
    }
}