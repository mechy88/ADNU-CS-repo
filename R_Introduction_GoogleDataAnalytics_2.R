# working with pipes
library(tidyverse)
library(dplyr)

data("ToothGrowth")
View(ToothGrowth)

filtered_tg <- filter(ToothGrowth, dose==0.5)
View(filtered_tg)

#arrange(filtered_tg, len)

#arrange(filter(ToothGrowth, dose==0.5), len)

# filtered_toothgrowth <- ToothGrowth %>% 
#   filter(dose==0.5) %>% 
#   arrange(len)

filtered_toothgrowth <- ToothGrowth %>% 
  filter(dose==0.5) %>% 
  group_by(supp) %>% 
  summarize(mean_len = mean(len, na.rm = T), .group = "drop")

filtered_toothgrowth

