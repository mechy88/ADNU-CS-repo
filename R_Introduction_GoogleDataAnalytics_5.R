# Cleaning up with the basics
penguins %>% 
  select(-species)

penguins %>% 
  rename(new=species)

rename_with(penguins, tolower)

x <- c(3, 5, 7)
y <- c(2, 4, 6)
x < 5 & y < 5