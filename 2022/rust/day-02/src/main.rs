use std::fs::read_to_string;

fn part_1(){
    let mut score = 0;
    let win = [
        "C X",
        "A Y",
        "B Z"
    ];
    let tie = [
        "A X",
        "B Y",
        "C Z"
    ];
    let lose = [
        "B X",
        "C Y",
        "A Z"
    ];

    let states = [lose, tie, win];

    for game in read_to_string("./input.txt").unwrap().lines() {
        for (i, state) in states.iter().enumerate() {
            for (ii, outcome) in state.iter().enumerate() {
                if &game == outcome {
                    score += i * 3 + ii + 1;
                }
            }
        }
    }
    println!("{}", score);

}

fn part_2() {
    let mut score = 0;
    let rock = [
        "B X",
        "A Y",
        "C Z"
    ];
    let paper = [
        "C X",
        "B Y",
        "A Z"
    ];
    let scissors = [
        "A X",
        "C Y",
        "B Z"
    ];

    let states = [rock, paper, scissors];

    for game in read_to_string("./input.txt").unwrap().lines() {
        'outer: for (i, state) in states.iter().enumerate() {
            for (ii, outcome) in state.iter().enumerate() {
                if &game == outcome {
                    score += ii * 3 + i + 1;
                    break 'outer
                }
            }
        }
    }
    println!("{}", score);
}


fn main() {
    part_1();
    part_2();
}