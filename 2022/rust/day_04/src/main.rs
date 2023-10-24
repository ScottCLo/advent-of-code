use std::{fs::read_to_string, ops::RangeInclusive};

fn range_contains_range(a: &RangeInclusive<u32>, b: &RangeInclusive<u32>) -> bool {
    if a.clone()
        .map(move |x| b.contains(&x))
        .collect::<Vec<bool>>()
        .contains(&false)
    {
        false
    } else {
        true
    }
}

fn part_1(file_path: &str) -> u32 {
    read_to_string(file_path)
        .unwrap()
        .lines()
        .map(|x| {
            let pair = x
                .split(",")
                .map(|x| {
                    let x = x
                        .split("-")
                        .map(|x| String::from(x).parse::<u32>().unwrap())
                        .collect::<Vec<u32>>();
                    x[0]..=x[1]
                })
                .collect::<Vec<RangeInclusive<u32>>>();
            if range_contains_range(&pair[0], &pair[1]) || range_contains_range(&pair[1], &pair[0])
            {
                1
            } else {
                0
            }
        })
        .sum::<u32>()
}

fn main() {
    println!("Part 1: {}", part_1("./input.txt"));
}
