use std::fs::read_to_string;

#[derive(Debug)]
struct Puzzle {
    state: Vec<Vec<char>>,
}

impl Puzzle {
    fn from_str(s: &str) -> Puzzle {
        let mut state: Vec<Vec<char>> = Vec::new();
        let x = s
            .lines()
            .rev()
            .skip(1) //discard the label row
            .map(|l| {
                let mut c = l.chars();
                let mut line: Vec<char> = Vec::new();
                while let (Some(_), Some(x), Some(_)) = (c.next(), c.next(), c.next()) {
                    line.push(x);
                    c.next();
                }
                line
            });
        for l in x {
            for (i, c) in l.iter().enumerate() {
                if state.len() < i + 1 {
                    state.push(Vec::new());
                }
                if c.is_alphabetic() {
                    state[i].push(*c);
                }
            }
        }
        Puzzle { state }
    }

    fn move_qty(&mut self, m: (usize, usize, usize)) {
        let range = self.state[m.1].len() - m.0..;
        let x = self.state[m.1].drain(range).rev().collect::<Vec<char>>();
        self.state[m.2].extend(x);
    }

    fn move_multiple(&mut self, m: (usize, usize, usize)) {
        let range = self.state[m.1].len() - m.0..;
        let x = self.state[m.1].drain(range).collect::<Vec<char>>();
        self.state[m.2].extend(x);
    }

    fn top_row(&self) -> String {
        self.state.iter().map(|x| x.last().unwrap()).collect()
    }
}

fn parse_input (file_path: &str) -> (Puzzle, Vec<(usize,usize,usize)>){
    let input = read_to_string(file_path).unwrap();
    let (puzzle, instructions) = input.split_at(input.find("\r\n\r").unwrap());
    let mut puzzle: Puzzle = Puzzle::from_str(puzzle);
    let instructions = instructions.trim().lines().map(|x| {
        x.split(" ")
            .filter_map(|x| x.parse::<usize>().ok())
            .collect::<Vec<usize>>()
    }).map(|x| (x[0],x[1]-1,x[2]-1)).collect::<Vec<(usize,usize,usize)>>();
    (puzzle, instructions) 
}

fn part_1(file_path: &str) -> String {
    let (mut puzzle, steps) = parse_input(file_path);
    for m in steps {
        puzzle.move_qty(m);
    }
    puzzle.top_row()
}

fn part_2(file_path: &str) -> String {
    let (mut puzzle, steps) = parse_input(file_path);
    for m in steps {
        puzzle.move_multiple(m);
    }
    puzzle.top_row()
}


fn main() {
    println!("Part 1: {}", part_1("input.txt"));
    println!("Part 2: {}", part_2("input.txt"));
}
