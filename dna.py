string_1 = "C A G A A A A T T A C T G G A T A A T A A"

string_2 = "T T A G C G G"

string_1_split = string_1.split()
# print(len(string_1_split))
string_2_split = string_2.split()
# print(len(string_2_split))

# k = 0

# counter_list = []

# # for k in string_1_split:
# #     for j in string_2_split:


# for k in range (len(string_1_split)):
#     j = 0
#     counter = 0
#     list_string = []

#     for i in range(k, len(string_1_split)):
#         counter_j = 0
#         while (j < len(string_2_split)):

#             print("------START-----")
#             print("---STRING1---")
#             print(string_1_split[i])
#             print("---STRING2---")
#             print(string_2_split[j])
#             print("-------END------")

#             if string_1_split[i] == string_2_split[j]:
#                 list_string.append(string_1_split[i])
#                 counter +=1
#                 j += 1
#                 break
#             else:
#                 counter_j += 1
            
#         j = j - counter_j


#     print(list_string)
#     print("//////////////////////////////////////////////////")
#     counter_list.append(counter)


# print(len(counter_list))
# print(max(counter_list))

# i = 0
# j = 0
# counter = 0
# while(i < len(string_1_split)):
#     while(j < len(string_2_split)):
#         if string_1_split[i] == string_2_split[j]:
#             i += 1
#             counter += 1
#         else:
#             j += 1
#     break

k = 0

counter_list = []

for k in range (len(string_1_split)):
    i = 0
    j = 0
    counter = 0
    while(i < len(string_1_split)):
        while(j < len(string_2_split)):
            if string_1_split[i] == string_2_split[j]:
                i += 1
                j += 1
                counter += 1
            else:
                j += 1
        break
    counter_list.append(counter)


print(counter_list)
print(max(counter_list))