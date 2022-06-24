#!/usr/bin/env python
# -*- coding: utf-8 -*-

from array import *

class Graph:
    def __init__(self, maxX=9, maxY=4):
        self.m_x = maxX
        self.m_y = maxY
        
        self.m_map = []
        line = []
        i=0

        for j in range(self.m_y):
            for k in range(self.m_x):
                line.append(i)
                i+=1
            self.m_map.append(line)
            line=[]
    
    def Neighbor4(self, x, y): #return [(x,y), (x,y)...], 不含对角线
        # 先写一个通用算法，然后再考虑边界条件
        ret = []
        if y>0:          ret.append( (x, y-1) )
        if x>0:          ret.append( (x-1, y) )
        if x<self.m_x-1: ret.append( (x+1, y) )
        if y<self.m_y-1: ret.append( (x, y+1) )
        return ret


    def Neighbor8(self, x, y): #return [(x,y), (x,y)...], 包含对角线
        ret = []
        if x>0 and y>0:          ret.append( (x-1, y-1) )
        if y>0:                  ret.append( (x, y-1) )
        if x<self.m_x-1 and y>0: ret.append( (x+1, y-1) )

        if x>0:                  ret.append( (x-1, y) )
        if x<self.m_x-1:         ret.append( (x+1, y) )

        if x>0 and y<self.m_y-1: ret.append( (x-1, y+1) )
        if y<self.m_y-1:         ret.append( (x, y+1) )
        if x<self.m_x-1 and y<self.m_y-1: ret.append( (x+1, y+1) )

        return ret


if __name__ == "__main__":
    g = Graph(9, 4)
    
    #print(g.m_map)

    #print(g.Neighbor8(0, 0))        #[(1, 0), (0, 1), (1, 1)]
    #print(g.Neighbor8(0, 1))
    #print(g.Neighbor8(0, 8))

    #print(g.Neighbor8(1, 0))
    #print(g.Neighbor8(1, 1))
    #print(g.Neighbor8(1, 8))

    #print(g.Neighbor8(3, 8))

    #print(g.Neighbor4(0, 0))
    #print(g.Neighbor4(0, 1))
    #print(g.Neighbor4(0, 8))

    #print(g.Neighbor4(1, 0))
    #print(g.Neighbor4(1, 1))
    #print(g.Neighbor4(1, 3))

    print(g.Neighbor4(3, 1))
    #print(g.Neighbor4(3, 8))
    #print(g.Neighbor4(2, 2))