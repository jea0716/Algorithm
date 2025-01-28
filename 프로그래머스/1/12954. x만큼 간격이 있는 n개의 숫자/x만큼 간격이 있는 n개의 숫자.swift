func solution(_ x:Int, _ n:Int) -> [Int64] {
    var curr: Int = x
    var arr: [Int64] = []
    
    for i in 1...n {
        arr.append(Int64(x * i))
    }
    
    return arr
}