class MovieRentingSystem {
    Comparator<Entry> comparator = (o1, o2) -> {
        if (o1.price != o2.price) return Integer.compare(o1.price, o2.price);
        if (o1.shop != o2.shop) return Integer.compare(o1.shop, o2.shop);
        return Integer.compare(o1.movie, o2.movie);
    };
    HashMap<Integer, Set<Entry>> unrented = new HashMap<>(); // Map moveId -> TreeSet of Entries
    HashMap<Pair<Integer, Integer>, Integer> price = new HashMap(); // Map (shop, movie) -> price
    TreeSet<Entry> rented = new TreeSet<>(comparator);
   
    public MovieRentingSystem(int n, int[][] entries) {
        for (int[] entry : entries) {
            int s = entry[0], m = entry[1], p = entry[2];
            unrented.computeIfAbsent(m, x -> new TreeSet<>(comparator)).add(new Entry(p, s, m));
            price.put(new Pair(s, m), p);
        }
    }
    public List<Integer> search(int movie) {
        return unrented.getOrDefault(movie, Collections.emptySet()).stream().limit(5).map(e -> e.shop).collect(Collectors.toList());
    }
    public void rent(int shop, int movie) {
        int p = price.get(new Pair(shop, movie));
        unrented.get(movie).remove(new Entry(p, shop, movie));
        rented.add(new Entry(p, shop, movie));
    }
    public void drop(int shop, int movie) {
        int p = price.get(new Pair(shop, movie));
        unrented.get(movie).add(new Entry(p, shop, movie));
        rented.remove(new Entry(p, shop, movie));
    }
    public List<List<Integer>> report() {
        return rented.stream().limit(5).map(e -> List.of(e.shop, e.movie)).collect(Collectors.toList());
    }
    class Entry {
        int price, shop, movie;
        public Entry(int price, int shop, int movie) {
            this.price = price;
            this.shop = shop;
            this.movie = movie;
        }
    }
}
