public class Brute{
    public static long brute() {
        long accumulator = 0;
        for (int i = 0; i < 1000; i++) {
            if (i % 3 == 0 || i % 5 == 0) {
                accumulator += i;
            }
        }
        return accumulator;
    }

    public static void main(String[] args) {
        long result = brute();
        double total_time = 0;
        int num_iterations = 100;

        for (int i = 0; i < num_iterations; i++) {
            double startTime = System.nanoTime();
            brute();
            double endTime = System.nanoTime();
            double duration = endTime - startTime;
            total_time += duration;
        }

        long average_time = (long) (total_time / num_iterations);
        String averageTimeString = String.valueOf(average_time);
        
        System.out.println(result);
        System.out.println(averageTimeString);
    }
}