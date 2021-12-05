package Problem_1032;

import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        List<String> strList = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            String str = sc.nextLine();
            strList.add(str);
        }

        String answer = "";

        for (int i = 0; i < strList.get(0).length(); i++) {
            boolean check = true;

            for (int j = 1; j < strList.size(); j++) {
                if (!Character.toString(strList.get(0).charAt(i))
                        .equals(Character.toString(strList.get(j).charAt(i)))) {
                    check = false;
                }
            }

            if (check) {
                answer += strList.get(0).charAt(i);
            } else {

                answer += "?";
            }
        }

        System.out.println(answer);
    }
}
