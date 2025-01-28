import Foundation

func solution(_ park:[String], _ routes:[String]) -> [Int] {
    let col: Int = park.count
    let row: Int = park[0].length
    var map: [[Int]] = Array(repeating: Array(repeating: 0, count: 50), count : 50)
    var curr: [Int] = [0, 0]
    
    for i in 0 ..< park.count {
        for j in 0 ..< park[i].length {
            let curIdx = park[i].index(park[i].startIndex, offsetBy: j)
            if String(park[i][curIdx]) == "S" {
                curr[0] = i
                curr[1] = j
            } else if String(park[i][curIdx]) == "X" {
                map[i][j] = 1
            }
        }
    }
    
    for route in routes {
        let dir = route[route.index(route.startIndex, offsetBy: 0)]
        let cnt: Int = Int(String(route[route.index(route.startIndex, offsetBy: 2)]))!
        
        var check: Bool = false
        
        if dir == "E" && curr[1] + cnt < row {
            for i in 1...cnt {
                if map[curr[0]][curr[1] + i] == 1 {
                    check = true;
                }
            }
            if !check {
                curr[1] += cnt
            }
        } else if dir == "W" && curr[1] - cnt >= 0 {
            for i in 1...cnt {
                if map[curr[0]][curr[1] - i] == 1 {
                    check = true;
                }
            }
            if !check {
                curr[1] -= cnt
            }
        } else if dir == "N" && curr[0] - cnt >= 0 {
            for i in 1...cnt {
                if map[curr[0] - i][curr[1]] == 1 {
                    check = true;
                }
            }
            if !check {
                curr[0] -= cnt
            }
        } else if dir == "S" && curr[0] + cnt < col {
            for i in 1...cnt {
                if map[curr[0] + i][curr[1]] == 1 {
                    check = true;
                }
            }
            if !check {
                curr[0] += cnt
            }
        }
    }
    
    return curr
}