package mypackage;

import java.util.Locale;
/**
 * The class principal
 */
public class Main{
    /**
     * The main program
     * @param args Vainas y mas vainas
     */
    public static void main(String[] args){
        //Values ​​of challenge 1 of the Euler project, For simplicity they are defined as 'int', but functions work with 'long long'
        long up_bound = 1000;
        long multiple1 = 3;
        long multiple2 = 5;
        //Variables for time measurement
        long res = 0;
        double total_time = 0;
        int num_interations = 100;
        //Warm-up execution, prepares the system to perform iterative execution and better measure the execution time
        long result = MyModule.solve(up_bound, multiple1, multiple2);
        //Measuring the average time gives a better result than measuring a single execution.
        for (int i=0; i < num_interations; i++){ 
            double startTime = System.nanoTime(); //Measuring time in nanoseconds improves precision as the processes are 'simple'
            res = MyModule.solve(up_bound, multiple1, multiple2);
            double endTime = System.nanoTime();
            double duration = endTime - startTime;
            total_time+= duration;
        }
        if (res==result){ //Just to make use of the 'res' variable
            System.out.println("\tResult: " + result);
        }
        String average_time = String.format(Locale.US, "%.3e", total_time / num_interations / 1000000000); //Division by 1e9 to convert nanoseconds to seconds.
        //Note: Locale.Us --> This forces the system to use '.' as a decimal separator instead of ',' which is the one used by default.
        System.out.println("\tAverage time: " + average_time + "s");
    }
}