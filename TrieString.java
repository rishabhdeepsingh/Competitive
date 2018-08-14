package FastIO;


public class TrieString {
    public static int SIZE = 256;
    public TrieString[] child = new TrieString[SIZE];
    public boolean end;

    public TrieString() {
        end = false;
        for (int i = 0; i < SIZE; i++) {
            child[i] = null;
        }
    }

    public void insert(String key) {
        TrieString crawl = this;
        for (int i = 0; i < key.length(); i++) {
            int index = key.charAt(i) - 'a';
            if (crawl.child[index] == null) {
                crawl.child[index] = new TrieString();
            }
            crawl = crawl.child[index];
        }
        crawl.end = true;
    }

    public boolean search(String key) {
        TrieString crawl = this;
        for (int i = 0; i < key.length(); i++) {
            int index = key.charAt(i) - 'a';
            if (crawl.child[index] == null)
                return false;
            crawl = crawl.child[index];
        }
        return (crawl != null && crawl.end);
    }
}
