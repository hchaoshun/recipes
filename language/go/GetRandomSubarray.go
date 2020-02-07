func GetRandomSubarray(candidates []*common.Item, length int32) []*common.Item {
	result := make([]*common.Item, 0, length)
	if len(candidates) == 0 {
		return result
	}
	if len(candidates) <= int(length) {
		return candidates
	}
	rand.Shuffle(len(candidates), func(i, j int) {
		candidates[i], candidates[j] = candidates[j], candidates[i]
	})
	return candidates[:int(length)]
}
