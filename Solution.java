import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

class Result {
    public static List<String> funWithAnagrams(List<String> text) {
        Set<String> seenSignatures = new HashSet<>();
        List<String> result = new ArrayList<>();

        for (String word : text) {
            char[] chars = word.toCharArray();
            Arrays.sort(chars);
            String signature = new String(chars);

            if (!seenSignatures.contains(signature)) {
                seenSignatures.add(signature);
                result.add(word);
            }
        }

        Collections.sort(result);
        return result;
    }
}

public class Solution {
    public static void main(String[] args) {
        List<String> text1 = Arrays.asList("code", "aaagmnrs", "anagrams", "doce");
        List<String> output1 = Result.funWithAnagrams(text1);
        System.out.println("Sample 1 Output: " + output1);

        List<String> text2 = Arrays.asList("code", "doce", "ecod", "framer", "frame");
        List<String> output2 = Result.funWithAnagrams(text2);
        System.out.println("Sample 2 Output: " + output2);
    }
}