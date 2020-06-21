package main

import "fmt"

type user struct {
	ID   string
	Name string
}

func main() {
	users := []user{
		user{ID: "1", Name: "Go"},
		user{ID: "2", Name: "C++"},
	}

	//注意umap存储的值取决于for循环最后的值
	umap := make(map[string]*user)
	// 把users 转umap
	for _, u := range users {
		//newUser := user{u.ID, u.Name}
		//umap[u.ID] = &newUser
		umap[u.ID] = &u
	}

	for k, v := range umap {
		fmt.Println("k: ", k)
		fmt.Println("v: ", v)
	}

}
