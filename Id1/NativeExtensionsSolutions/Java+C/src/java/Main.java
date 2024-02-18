public class Main {
    static {
        String libraryPath = "/home/effez/EulerProject/Id1/withC/Java+C/bin/c/libMymodule.so";

        try {
            System.load(libraryPath);
        } catch (UnsatisfiedLinkError e) {
            System.err.println("Error al cargar la biblioteca: " + e.getMessage());
            System.exit(1);
        }
    }

    public native static long solve(long up_bound, long multiple1, long multiple2);

    public static void main(String[] args) {
        Mymodule sumador = new Mymodule();
        //For better understanding, first look at 'main.java'
        long up_bound = 1000;
        long multiple1 = 3;
        long multiple2 = 5;

        long res = 0;
        if (args.length == 3) { //checks if parameters have been passed and handles them as expected.
            try {
                up_bound = Long.parseLong(args[0]);
                multiple1 = Long.parseLong(args[1]);
                multiple2 = Long.parseLong(args[2]);
                if (up_bound<multiple1 || up_bound<multiple2) { //Check that the 'up_bound' is greater than the multiples.
                    System.out.println("Error: 'up_bound' must be greater than multiples.");
                    return;
                } else if (up_bound < 0 || multiple1 < 0 || multiple2 < 0){
                    System.out.println("Error: Only positive integers are allowed");
                    return;
                }
            } catch (NumberFormatException e) {
                System.out.println("Error: Three integers numbers expected <up_bound> <multiple1> <multiple2>");
                return;
            }
        }

        double total_time = 0;
        int num_interations = 100;
        long result = sumador.solve(up_bound,multiple1,multiple2);        
        for (int i=0; i<num_interations; i++) {
            double startTime = System.nanoTime();
            res = sumador.solve(up_bound,multiple1,multiple2);
            double endTime = System.nanoTime();
            double duration = endTime - startTime;
            total_time += duration;
        }
        if (res == result) {
            System.out.println(result);
        }
        
        long averageTime = (long) (total_time / num_interations); 
        String averageTimeString = String.valueOf(averageTime); // Here it send the time in integer nanoseconds to work with the result with bash
        System.out.println(averageTimeString);
    }
}