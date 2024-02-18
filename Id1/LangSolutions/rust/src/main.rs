mod module;
use std::time::Instant;

/// The main code is practically the same for all the challenges of the Euler Project,
/// the only changes are those referring to the variables and value of the challenge
/// to be solved.
/// # Note
/// For information on the logic see 'mylib.py' in the module folder
fn main() {
    //Values ​​of challenge 1 of the Euler project.
    let up_bound = 1000;
    let multiple1 = 3;
    let multiple2 = 5;
    //Warm-up execution, prepares the system to perform iterative execution and better measure the execution time
    let result = module::solve(up_bound - 1, multiple1, multiple2);
    //Variables for time measurement
    let mut total_duration = 0f64;
    let num_executions = 100;
    for _ in 0..num_executions {
        let start = Instant::now(); //Start of time measurement
        module::solve(up_bound - 1, multiple1, multiple2);
        let duration = start.elapsed(); //End of time measurement
        total_duration += duration.as_secs_f64();
    }
    let average_duration = total_duration / num_executions as f64; //converts the result to float, by default it comes in ..μs format
    println!("\tResult: {}", result);
    println!("\tAverage time: {:.3e}s", average_duration);    
}