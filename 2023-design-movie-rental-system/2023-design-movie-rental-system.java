import java.util.*;

public class MovieRentingSystem {
    private final Map<Long, Integer> shopMap = new HashMap<>();
    private final Map<Integer, NavigableSet<Pair>> movieMap = new HashMap<>();
    private final NavigableSet<Triple> rented = new TreeSet<>();

    private static long key(int shop, int movie) {
        return (((long) shop) << 32) | (movie & 0xFFFFFFFFL);
    }

    public MovieRentingSystem(int n, int[][] entries) {
        for (int[] e : entries) {
            int shop = e[0];
            int movie = e[1];
            int price = e[2];
            shopMap.put(key(shop, movie), price);
            movieMap.computeIfAbsent(movie, k -> new TreeSet<>()).add(new Pair(price, shop));
        }
    }

    public MovieRentingSystem(int n, List<List<Integer>> entries) {
        for (List<Integer> e : entries) {
            int shop = e.get(0);
            int movie = e.get(1);
            int price = e.get(2);
            shopMap.put(key(shop, movie), price);
            movieMap.computeIfAbsent(movie, k -> new TreeSet<>()).add(new Pair(price, shop));
        }
    }

    public List<Integer> search(int movie) {
        List<Integer> ans = new ArrayList<>();
        NavigableSet<Pair> set = movieMap.get(movie);
        if (set == null) return ans;
        int i = 0;
        for (Pair p : set) {
            if (i++ >= 5) break;
            ans.add(p.shop);
        }
        return ans;
    }

    public void rent(int shop, int movie) {
        long k = key(shop, movie);
        Integer price = shopMap.get(k);
        if (price == null) return;
        Pair p = new Pair(price, shop);
        NavigableSet<Pair> set = movieMap.get(movie);
        if (set != null) set.remove(p);
        rented.add(new Triple(price, shop, movie));
    }

    public void drop(int shop, int movie) {
        long k = key(shop, movie);
        Integer price = shopMap.get(k);
        if (price == null) return;
        Triple t = new Triple(price, shop, movie);
        rented.remove(t);
        movieMap.computeIfAbsent(movie, m -> new TreeSet<>()).add(new Pair(price, shop));
    }

    public List<List<Integer>> report() {
        List<List<Integer>> ans = new ArrayList<>();
        int i = 0;
        for (Triple t : rented) {
            if (i++ >= 5) break;
            ans.add(Arrays.asList(t.shop, t.movie));
        }
        return ans;
    }

    private static final class Pair implements Comparable<Pair> {
        final int price;
        final int shop;

        Pair(int price, int shop) {
            this.price = price;
            this.shop = shop;
        }

        @Override
        public int compareTo(Pair o) {
            if (this.price != o.price) return Integer.compare(this.price, o.price);
            return Integer.compare(this.shop, o.shop);
        }

        @Override public boolean equals(Object obj) {
            if (this == obj) return true;
            if (!(obj instanceof Pair)) return false;
            Pair other = (Pair) obj;
            return this.price == other.price && this.shop == other.shop;
        }

        @Override public int hashCode() {
            return Objects.hash(price, shop);
        }
    }

    private static final class Triple implements Comparable<Triple> {
        final int price;
        final int shop;
        final int movie;

        Triple(int price, int shop, int movie) {
            this.price = price;
            this.shop = shop;
            this.movie = movie;
        }

        @Override
        public int compareTo(Triple o) {
            if (this.price != o.price) return Integer.compare(this.price, o.price);
            if (this.shop != o.shop) return Integer.compare(this.shop, o.shop);
            return Integer.compare(this.movie, o.movie);
        }

        @Override public boolean equals(Object obj) {
            if (this == obj) return true;
            if (!(obj instanceof Triple)) return false;
            Triple other = (Triple) obj;
            return this.price == other.price && this.shop == other.shop && this.movie == other.movie;
        }

        @Override public int hashCode() {
            return Objects.hash(price, shop, movie);
        }
    }
}