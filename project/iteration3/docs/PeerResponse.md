**RESPONDER: Renda Zhang**

**AUTHOR: Corey Tesdahl**

  1. In the first paragraph of the mainpage, what is the most effective sentence with respect to orienting the reader to the project?

- The most effective sentence is "Player is controlled by keyboard input moving indside Arena, and win the game by freezing all robots, and lose the game when all Robot become SuperBot."

  2. Identify a sentence in the first paragraph that needs to be reworked and state what you think is problematic about that sentence. (Do not edit it.)

- This sentence "Player have RobotBattery inside, and battery is decreased by time, if batttery is out, lose." need to be reworked. Because it didn't specify What is RobotBattery, and the naming "RobotBattery" is also confusing to readers.

  3. Identify a sentence or two in any of the paragraphs that provides the "big picture" with respect to the software, design, or class structure, AND is accompanied by low-level details that help the reader better understand the "big picture."

- The sentence is "Arena have control over all entities and handle all the Events pass to Sensors. Entities are broken down into ArenaMobileEntity and ArenaImmobileEntity. All ArenaMobileEntity have sensors in them to recieve update from arena."

  4. Comment on the effectiveness of this technique in the example from (3). If it is effective, analyze why you think it works here. If you think there are other details that would be more elucidating, state those.

- It is effective. Because it crealy telling how the code work generally and introduce the lower details of different kinds of entities.

  5. Identify a topic in the writing that is either underspecified or is discussed too in-depth. If underspecified, what is the most important idea that is missing? If too in-depth, what can be removed?

- The last sentence "The different MotionHandler are: MotionHandlerHomeBase, MotionHandlerPlayer, MotionHandlerRobot, MotionHandlerSuperBot." is underspecified. Because it didn't give more detailes about why used different Motion handler for different entities.

  6. What do you think would be the single most impactful change to this document - in other words, what would you recommend to the author as the one area on which to focus? It could be related to the content (e.g. level of detail, more or less technical information, highlight more or fewer classes, etc.) or to the writing (e.g. reorganize paragraph or sentence order, condense text, improve sentence structure, etc.).

- It should have more detail about the techinical aspect of how sensors are implemented in the code.

  7. As a programmer new to this project, which class do you think the document is emphasizing as the place to begin to engage the code? This might be explicit or implicit. What part of the writing made you think you should start with that class?

- I think the Arena class would be the place to begin to engage the code as what the document is emphasizing. Because it clearly show that Arena have control over every entities.

  Now explore the documentation of the classes. Go to the class that you identified in (7).

  8. What do you consider to be the best and worst documented method in that class and why. OR, if you think they are all of equal quality, comment on the level of detail provided in the documentation. Is it sufficient, clear, and correct? If it is excellent, state what makes it excellent.

- They are all of eual quality. It is sufficient, clear and correct. New programmer can understand the function without any problems. 

  9. Skim through all the brief comments on the main classes page. What strikes you as you look at the collection? Is there an effective pattern in the comments? Is there something consistently lacking?

- It strikes me that some class have long comments while some have shor comments. The pattern is that it all have easy comments. it need to have more consistency by adding more details to the comments for some classes for new programmer to understand it.

  Now look at the UML - be conscious of your first reaction!

  10. Where did your eye go? What jumps out at you on the page? Is this an important element, thus warrants the attention? If not, offer a suggestion on how to make it less visually prominent.

- My eye go at the center of the page. Lots of differents classes jumps out. The important element is that they looks consistent and easy to understand.

  11. What did the author do in her/his UML diagram that you would like to incorporate into your UML? Why do you like that part of the UML and how does it differ from what you did?

- The best thing I want to incorporate is the simple structure that this author used for his UML. My structure is way more complex than his. So his UML is easy to understand.

  12. Try to recall your sense of your first attempt to engage the base code, and think of how it is even more complex now. Keeping that in mind, what do you think was the most successful part of the author's writing (in doxygen and UML) with respect to helping a programmer get acclimated to the code? What do you think could be very helpful but needs some rework?

- The most successful part is that this author make everything easy to understand. It will be better if more details can be provided in the comment of the classses.
