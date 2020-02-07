func GetRandomSubarrayInt64(candidates []int64, length int) []int64 {
    result := make([]int64, 0, length)
    if len(candidates) == 0 {
        return result
    }
    if len(candidates) <= length {
        return candidates
    }
    rand.Shuffle(len(candidates), func(i, j int) {
        candidates[i], candidates[j] = candidates[j], candidates[i]
    })
    return candidates[:length]
}


func GetRandomSubarrayString(candidates []string, length int) []string {
    result := make([]string, 0, length)
    if len(candidates) == 0 {
        return result
    }
    if len(candidates) <= length {
        return candidates
    }
    rand.Shuffle(len(candidates), func(i, j int) {
        candidates[i], candidates[j] = candidates[j], candidates[i]
    })
    return candidates[:length]
}
