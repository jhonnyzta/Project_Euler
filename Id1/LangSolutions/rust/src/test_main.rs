mod module;
use std::time::Instant;
use std::env;

fn main() {
    //For better understanding, first look at 'main.rs'
    let mut up_bound = 1000; //Default values
    let mut multiple1 = 3;
    let mut multiple2 = 5;

    let args: Vec<String> = env::args().collect();
    if args.len() == 4 { //checks if parameters have been passed and handles them as expected.
        up_bound = args[1].parse::<i64>().expect("Error: The first argument must be an integer.");
        multiple1 = args[2].parse::<i64>().expect("Error: The second argument must be an integer.");
        multiple2 = args[3].parse::<i64>().expect("Error: The third argument must be an integer.");
        if up_bound<multiple1 || up_bound<multiple2{ //Check that the 'up_bound' is greater than the multiples.
            println!("Error: 'up_bound' must be greater than multiples.");
            return;
        } else if up_bound<0 || multiple1<0 || multiple2<0{
            println!("Error: Only positive integers are allowed");
            return;
        }
    } else if args.len()>1{
        println!("Error: Three integers numbers expected <up_bound> <multiple1> <multiple2>");
        return;
    }
    let result = module::solve(up_bound, multiple1, multiple2);
    let mut total_duration = 0f64;
    let num_executions = 100;
    for _ in 0..num_executions {
        let start = Instant::now();
        module::solve(up_bound, multiple1, multiple2);
        let duration = start.elapsed();
        total_duration += duration.as_secs_f64();
    }
    let average_duration = ((total_duration / num_executions as f64)*1e9) as i64; // Here it send the time in integer nanoseconds to work with the result with bash
    println!("{}", result);
    println!("{}", average_duration);    
}