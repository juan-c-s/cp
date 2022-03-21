package Competitiva.clase1.Warmup;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class TheatreSquare {

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        String num = bf.readLine();
        String[] nums = num.split(" ");

        double n = Integer.parseInt(nums[0]);
        double m = Integer.parseInt(nums[1]);
        double a = Integer.parseInt(nums[2]);

        double tiles = (Math.ceil(m / a) * Math.ceil(n / a));
        System.out.println((long) tiles);

    }
}
