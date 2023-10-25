use std::fs::read_to_string;
use itertools::Itertools;

fn find_first_unique(len: usize,  string: &String) -> Option<usize>{
    let mut packet :Vec<char> = Vec::new();
    let mut input = string.chars();
    for _ in 0..len {
        packet.push(input.next().unwrap());
    }
    for (i, c) in input.enumerate(){
        if packet.iter().unique().collect::<Vec<&char>>().len() == len {
            return Some(i + len);
        } else {
            packet.remove(0);
            packet.push(c);
        }
    }
    None
}




fn main() {
    let input = read_to_string("input.txt").unwrap();
    println!("Part 1: {:?}", find_first_unique(4, &input).unwrap());
    println!("Part 2: {:?}", find_first_unique(14, &input).unwrap());
}
