use std::time::Instant;

fn brute() -> i64 {
    let mut accumalator: i64 = 0;
    for i in 1..1000 {
        if i % 3 == 0 || i % 5 == 0 {
            accumalator += i;
        }
    }
    accumalator
}

fn main() {
    let mut total_duration = 0f64;
    let num_executions = 100;
    let result = brute();
    for _ in 0..num_executions {
        let start = Instant::now();
        brute();
        let duration = start.elapsed();
        total_duration += duration.as_secs_f64();
    }
    let average_time = ((total_duration / num_executions as f64)*1e9) as i64;
    println!("{}", result);
    println!("{}", average_time);
}