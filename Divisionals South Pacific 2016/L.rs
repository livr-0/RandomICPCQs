use std::{
    collections::{BTreeMap, BTreeSet},
    io::{self, BufRead},
};

#[derive(Debug)]
struct Header {
    left: usize,
    right: usize,
    chemicals: usize,
    _rules: usize,
}

fn parse_header(line: &str) -> Header {
    let nums: Vec<usize> = line
        .split_whitespace()
        .map(|x| x.parse().unwrap())
        .collect();

    Header {
        left: nums[0],
        right: nums[1],
        chemicals: nums[2],
        _rules: nums[3],
    }
}

fn parse_rule(line: &str) -> (usize, usize) {
    let nums: Vec<usize> = line
        .split_whitespace()
        .map(|x| x.parse().unwrap())
        .collect();
    (nums[0], nums[1])
}

fn main() {
    let mut input_lines = io::stdin().lock().lines();
    let header = parse_header(&input_lines.next().unwrap().unwrap());
    let mut rules: BTreeMap<usize, BTreeSet<usize>> = BTreeMap::new();

    for rule in input_lines {
        let rule = parse_rule(&rule.unwrap());
        rules.entry(rule.0).or_default().insert(rule.1);
        rules.entry(rule.1).or_default().insert(rule.0);
    }

    let mut groups = Vec::new();
    while let Some((&first, _)) = rules.first_key_value() {
        let mut queue = BTreeSet::new();
        let mut side_a = BTreeSet::new();
        let mut side_b = BTreeSet::new();

        queue.insert(first);
        side_a.insert(first);

        while let Some(chemical) = queue.pop_first() {
            for conflict in rules.remove(&chemical).unwrap() {
                let clash_a = side_a.contains(&chemical) && side_a.contains(&conflict);
                let clash_b = side_b.contains(&chemical) && side_b.contains(&conflict);
                if clash_a || clash_b {
                    println!("No");
                    return;
                }

                if side_a.contains(&chemical) {
                    side_b.insert(conflict);
                } else {
                    side_a.insert(conflict);
                }

                if rules.contains_key(&conflict) {
                    queue.insert(conflict);
                }
            }
        }
        groups.push((side_a.len(), side_b.len()))
    }

    let mut wave = BTreeSet::new();
    wave.insert(0);
    for group in groups {
        let mut new_wave = BTreeSet::new();
        for count in wave {
            let new_a = group.0 + count;
            let new_b = group.1 + count;
            if new_a <= header.left {
                new_wave.insert(new_a);
            }
            if new_b <= header.left {
                new_wave.insert(new_b);
            }
        }
        if new_wave.is_empty() {
            println!("No");
            return;
        }
        wave = new_wave;
    }

    let left_filled = wave.last().unwrap().clone();
    let right_filled = header.chemicals - left_filled;

    if left_filled <= header.left && right_filled <= header.right {
        println!("Yes");
    } else {
        println!("No");
    }
}

