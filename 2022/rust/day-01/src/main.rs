use std::fs::read_to_string;

fn part_1 () -> String{
    read_to_string("./input.txt")
        .unwrap()
        .split("\n\n")
        .map(|elf| elf.lines().map(|snaks| snaks.parse::<u32>().unwrap()).sum::<u32>())
        .max()
        .unwrap().to_string()
}

fn part_2 () -> String{
    let mut calories:Vec<u32> = read_to_string("./input.txt")
        .unwrap()
        .split("\n\n")
        .map(|elf| elf.lines().map(|snaks| snaks.parse::<u32>().unwrap()).sum::<u32>())
        .collect::<Vec<u32>>();
    calories.sort_by(|a, b| b.cmp(a));
    calories[0..3].iter().sum::<u32>().to_string()
}


fn main() {
    println!("Part 1: {}", part_1());
    println!("Part 2: {}", part_2());
}
