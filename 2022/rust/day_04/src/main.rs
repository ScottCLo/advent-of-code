use std::{fs::read_to_string, vec, io::BufRead};

struct Task {
    start: u32,
    end: u32,
}

impl Task {
    fn contrains_range(task: Task) -> bool{
        true
    }
}

fn part_1() {
    println!("WORK!");
    let input = read_to_string("./example.txt")
        .unwrap();
    let a = input
        .lines()
        .map(|x| {
            let pair = x.split(",").map(|x|{
                let x = x.split("-").map(|x| String::from(x).parse::<u32>().unwrap()).collect::<Vec<u32>>();
                Task{start: x[0], end: x[1]}
            })
            .collect::<Vec<Task>>();
            let task_range1 = (pair[0].start..pair[0].end);
            let task_range2 = (pair[1].start..pair[1].end);
            if task_range1.len() > task_range2.len() {

            }
        });
        
    
    println!("{:?}", a);
}

fn main() {
    //part_1();

}
