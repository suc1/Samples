#!/usr/bin/env python
# -*- coding: utf-8 -*-
# https://zhuanlan.zhihu.com/p/113008274

from queue import Queue

from graph import Graph

class Search:
    def __init__(self):
        #self.m_graph = Graph(9, 4)
        pass

    def BreadthFirstSearch(self):
        self.m_graph = Graph(9, 4)

        frontier = Queue()
        start = (3,1)
        frontier.put( start )
        visited = {}
        visited[start] = True

        while not frontier.empty():
            current = frontier.get()
            for next in self.m_graph.Neighbor4(current[0], current[1]):
                if next not in visited:
                    print(next)
                    frontier.put(next)
                    visited[next] = True

    def SearchRememberPath(self):
        self.m_graph = Graph(9, 4)

        frontier = Queue()
        start = (3,1)
        frontier.put( start )
        visited = {}            #Come from
        visited[start] = None

        while not frontier.empty():
            current = frontier.get()
            #if current==target:
                #GetPath()
                #return
            for next in self.m_graph.Neighbor4(current[0], current[1]):
                if next not in visited:
                    print(next)
                    frontier.put(next)
                    visited[next] = current

    def GetPath(self, start, goal, comeFrom):
        current = goal
        path = []
        while current != start:
            path.append(current)
            current = came_from[current]
        path.append(start) # optional
        path.reverse() # optional

if __name__ == "__main__":
    s = Search()
    #s.BreadthFirstSearch()
    s.SearchRememberPath()