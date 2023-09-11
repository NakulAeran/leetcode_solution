#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=460 lang=cpp
 *
 * [460] LFU Cache
 */

// @lc code=start

class Node
{
public:
    int key;
    int val;
    int freq;
    Node *prev;
    Node *next;
    Node(int k, int v)
    {
        key = k;
        val = v;
        freq = 1;
        prev = NULL;
        next = NULL;
    }
};

class LFUCache
{
private:
    int capacity;
    Node *head;
    Node *tail;
    unordered_map<int, Node *> cache;
    map<int, Node *> freq;

public:
    LFUCache(int capacity)
    {
        this->capacity = capacity;
        head = new Node(-1, -1);
        head->freq = INT_MAX;
        freq[INT_MAX] = head;
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node *curr)
    {
        auto temp = freq.upper_bound(curr->freq);
        curr->prev = temp->second;
        curr->next = temp->second->next;
        temp->second->next = curr;
        curr->next->prev = curr;
    }

    void deleteNode(Node *delnode)
    {
        Node *delprev = delnode->prev;
        Node *delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    int get(int key)
    {
        if (cache.find(key) != cache.end())
        {
            Node *delNode = cache[key];
            if (freq[delNode->freq] == delNode)
            {
                freq.erase(delNode->freq);
                if (delNode->prev->freq == delNode->freq)
                {
                    freq[delNode->prev->freq] = delNode->prev;
                }
            }
            deleteNode(delNode);
            delNode->freq++;
            addNode(delNode);
            freq[delNode->freq] = delNode;
            return delNode->val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (cache.find(key) != cache.end())
        {
            Node *delNode = cache[key];
            if (freq[delNode->freq] == delNode)
            {
                freq.erase(delNode->freq);
                if (delNode->prev->freq == delNode->freq)
                {
                    freq[delNode->prev->freq] = delNode->prev;
                }
            }
            deleteNode(delNode);
            delNode->freq++;
            delNode->val = value;
            addNode(delNode);
            freq[delNode->freq] = delNode;
            return;
        }
        if (cache.size() == capacity)
        {
            Node *delNode = tail->prev;
            cache.erase(delNode->key);
            if (freq[delNode->freq] == delNode)
            {
                freq.erase(delNode->freq);
                if (delNode->prev->freq == delNode->freq)
                {
                    freq[delNode->prev->freq] = delNode->prev;
                }
            }
            deleteNode(delNode);
        }
        Node *newNode = new Node(key, value);
        cache[key] = newNode;
        addNode(newNode);
        freq[newNode->freq] = newNode;
    }
};


int main(){
    LFUCache s(2);
    s.put(1,1);
    s.put(2,2);
    cout<<s.get(1)<<endl;
    s.put(3,3);
    cout<<s.get(2)<<endl;
    cout<<s.get(3)<<endl;
    s.put(4,4);
    cout<<s.get(1)<<endl;
    cout<<s.get(3)<<endl;
    cout<<s.get(4)<<endl;
    return 0;
}