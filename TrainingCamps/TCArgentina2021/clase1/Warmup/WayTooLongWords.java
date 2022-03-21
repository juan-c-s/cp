package Competitiva.clase1.Warmup;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class WayTooLongWords {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(bf.readLine());
        for (int i = 0; i < n; i++) {
            String tempWord = bf.readLine();
            if (tempWord.length() > 10) {
                tempWord = tempWord.charAt(0) + String.valueOf(tempWord.length() - 2)
                        + tempWord.charAt(tempWord.length() - 1);
            }
            System.out.println(tempWord);
        }
    }
}