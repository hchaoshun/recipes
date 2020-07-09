#include <iostream>
#include <algorithm>
#include "global.h"

//std::unordered_map<std::string, std::pair<double, double>> level_mapping_;
//std::vector<LabelItem> labels_;

int main() {
  LabelProfileDict label = LabelProfileDict(label_profile_name);
  if (label.load()) {
    auto level_mapping = label.getLevelMapping();
    auto labels = label.getLabels();

    std::for_each(level_mapping.begin(), level_mapping.end(), []
      (const std::pair<std::string, std::pair<double, double>>& p) {
      std::cout << p.first << " " << p.second.first << " " << p.second.second << std::endl;
    });

    std::for_each(labels.begin(), labels.end(), [](const LabelItem& item) {
      item.to_string();
    });

  } else {
    std::cout << "load error" << std::endl;
  }


  return 0;
}