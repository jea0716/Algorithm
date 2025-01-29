func solution(_ n:Int64) -> [Int] {
    
    var arr: [Int] = []
    var tmp: Int = Int(n)
    
    while tmp > 0 {
        arr.append(tmp % 10)
        tmp /= 10
    }
    
    return arr
}