package pq;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

import com.topcoder.shared.language.Language;
/**
 * @author Tim "Pops" Roberts
 *
 * Example post processor
 */

class MyProcessor {
	public String postProcess(String source, Language language) {
		if (!language.getName().equals("C++"))
			return source;
		String[] sourceWords = source.split("\\W");
		String[] sourceLines = source.split("\n");
		Map<String, Integer> wordsUsed = new HashMap<String, Integer>();
		for (String word : sourceWords) {
			if (wordsUsed.containsKey(word))
				wordsUsed.put(word, wordsUsed.get(word) + 1);
			else
				wordsUsed.put(word, 1);
		}
		StringBuilder result = new StringBuilder();
		boolean[] erase = new boolean[sourceLines.length];
		Arrays.fill(erase, false);
		for (int i = 0; i < sourceLines.length; i++) {
			if (sourceLines[i].length() < 5)
				continue;
			String signature = sourceLines[i].substring(0, 5);
			String[] words = sourceLines[i].split("\\W");
			if (signature.equals("class")) {
				break;
			} else if (signature.equals("#defi")) {
				String macroName = words[2];
				if (wordsUsed.get(macroName) < 2)
					erase[i] = true;
			} else if (signature.equals("typed")) {
				String typedefName = words[words.length - 1];
				if (wordsUsed.get(typedefName) < 2)
					erase[i] = true;
			} else if (signature.equals("const")) {
				String constName = words[2];
				if (wordsUsed.get(constName) < 2)
					erase[i] = true;
			} else if (signature.equals("templ") && words.length > 5) {
                String name = words[5];
                if (name.equals("mini") || name.equals("maxi")) {
                    if (wordsUsed.get(name) < 2) {
                        erase[i] = true;
                    }
                }
            }
		}
		for (int i = 0; i < sourceLines.length; i++) {
			if (!erase[i])
				result.append(sourceLines[i] + "\n");
		}
		return result.toString();
	}
};

public class MyPostProcessor {
	/**
	 * This method will process the source code prior to giving it to the applet
	 * 
	 * @param source the source code to modify
	 * @param language    the currently selected language
	 * @return returns the source code after modifications (if any)
	 */
	public String postProcess(String source, Language language) {
		return (new MyProcessor()).postProcess(source, language);
	}
}
