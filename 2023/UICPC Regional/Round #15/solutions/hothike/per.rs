use std::io::{self, BufRead};
use std::cmp;

fn main() {
    let stdin = io::stdin();
    stdin.lock().lines().next();
    let x: Vec<i32> = stdin.lock().lines().next().unwrap().unwrap().split_whitespace().map(|x| x.parse().unwrap()).collect();
    let it = x[2..].iter().zip(x.iter());
    let mut t = 50;
    let mut d = 0;
    for (i, (t1, t2)) in it.enumerate() {
        if cmp::max(t1, t2) < &t {
           t = cmp::max(*t1, *t2);
           d = i+1;
        }
    }
    println!("{} {}", d, t);
}
