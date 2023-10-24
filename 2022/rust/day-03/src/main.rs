use std::{fs::read_to_string, vec};

fn part_1(){
    let file = read_to_string("./input.txt");
    let x: u32 = file
        .unwrap()
        .lines()
        .map(|x| {
            let sack = x.split_at(x.len()/2);
            let item = sack.0
                .chars()
                .find(|c| sack.1.contains(*c))
                .unwrap();
            calculate_value(item)
        })
        .sum();
    println!("Part 1: {:?}", x);
}

fn part_2(){
    let file = read_to_string("./input.txt").unwrap();
    let mut lines = file
        .lines();
    let mut sum = 0;
    while let (Some(a), Some(b), Some(c)) = (lines.next(), lines.next(), lines.next()) {
        let y = a
            .chars()
            .find(|u| b.contains(*u) && c.contains(*u))
            .unwrap();
        sum += calculate_value(y);
    }
    println!("Part 1: {:?}", sum);
}

fn calculate_value(x: char) ->  u32{
    if x.is_uppercase(){
        x as u32 - 38
    } else {
        x as u32 - 96
    }
}

fn main(){
    part_1();
    part_2();
}
