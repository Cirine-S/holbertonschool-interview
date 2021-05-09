#!/usr/bin/python3
"""
This module contains a recursive function that queries the Reddit API,
parses the title of all hot articles, and prints a sorted count of
given keywords (case-insensitive, delimited by spaces. Javascript should
count as javascript, but java should not).
"""
import requests


def count_words(subreddit, word_list):
    """
    A recursive function that queries the Reddit API,
    parses the title of all hot articles,
    and prints a sorted count of given keywords
    """
    r = requests.get('https://www.reddit.com/r/{}/hot/.json'.format(subreddit))
