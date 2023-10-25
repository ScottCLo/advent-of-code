use std::fs::read_to_string;

struct Puzzle{
    puzzle: Vec<Vec<char>>
}

impl Puzzle {
    fn from_str(s: &str) -> Puzzle{
        s.lines().map(|x|{
            x.chars()
        });
        //return Puzzle{puzzle: vec![vec![' ']]};
    }
}

fn part_1(){
    let input = read_to_string("example.txt").unwrap();
    let (puzzle, instuctions) = input.split_at(input.find("\n\n").unwrap());
    let puzzle: Puzzle = Puzzle::from_str(puzzle);
}

fn main() {
    part_1();
}
